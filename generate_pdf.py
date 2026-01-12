import os
import subprocess
from fpdf import FPDF
from PIL import Image, ImageDraw, ImageFont

# Configuration
FILES = [
    ("1_validate_strings.cpp", "ababa"),
    ("2_prefix.cpp", "preface\npre"),
    ("3_suffix.cpp", "ending\ning"),
    ("4_substring.cpp", "banana\nnana"),
    ("5_dfa_aa.cpp", "bbaab"),
    ("6_dfa_mult3.cpp", "0001"), # 0s:3 (0 mod 3 == 0), 1s:1 
    ("7_nfa_consecutive.cpp", "bbaa"),
    ("8_moore_aab.cpp", "aabaabaaaab"),
    ("9_mealy_increment.cpp", "1011"),
    ("10_valid_c_id.cpp", "_validVar1"),
    ("11_valid_gmail.cpp", "testuser123@gmail.com"),
    ("12_valid_mac.cpp", "00:1A:2B:3C:4D:5E"),
    ("13_re_aa.cpp", "bbaab"),
    ("14_pda_anbn.cpp", "aaabbb"),
    ("15_tm_anbncn.cpp", "aabbcc")
]

PDF_OUTPUT = "Lab_Report_Aadarsha_Jha.pdf"
FONT_PATH = "C:/Windows/Fonts/consola.ttf" # Standard Windows Console Font
FONT_SIZE = 14
BG_COLOR = (12, 12, 12) # VS Code / Terminal dark theme background
TEXT_COLOR = (204, 204, 204) # Light gray text

class PDF(FPDF):
    def header(self):
        self.set_font('Arial', 'B', 12)
        self.cell(0, 10, 'Lab Exam Code Output', 0, 1, 'C')
        self.ln(5)

    def footer(self):
        self.set_y(-15)
        self.set_font('Arial', 'I', 8)
        self.cell(0, 10, 'Page ' + str(self.page_no()), 0, 0, 'C')

def compile_and_run(cpp_file, input_data):
    exe_name = cpp_file.replace(".cpp", ".exe")
    
    # Compile
    print(f"Compiling {cpp_file}...")
    compile_cmd = ["g++", "-o", exe_name, cpp_file]
    result = subprocess.run(compile_cmd, capture_output=True, text=True)
    if result.returncode != 0:
        return f"Compilation Failed:\n{result.stderr}"

    # Run
    print(f"Running {exe_name} with input: {input_data.replace(chr(10), ' ')}...")
    run_cmd = [f"./{exe_name}"]
    try:
        run_process = subprocess.run(run_cmd, input=input_data, capture_output=True, text=True, timeout=5)
        return run_process.stdout
    except subprocess.TimeoutExpired:
        return "Execution Timed Out"
    except Exception as e:
        return f"Execution Failed: {str(e)}"

def create_console_image(text, filename):
    # Calculate image size
    try:
        font = ImageFont.truetype(FONT_PATH, FONT_SIZE)
    except:
        font = ImageFont.load_default()
        print("Warning: Consola font not found, using default.")

    lines = text.split('\n')
    max_width = 0
    # Simple estimation or use font.getbbox (PIL 8.0+)
    dummy_draw = ImageDraw.Draw(Image.new('RGB', (1, 1)))
    
    for line in lines:
        bbox = dummy_draw.textbbox((0, 0), line, font=font)
        width = bbox[2] - bbox[0]
        if width > max_width:
            max_width = width
            
    line_height = int(FONT_SIZE * 1.5)
    img_width = max(800, max_width + 40) # Min width 800px, padding 40
    img_height = (len(lines) * line_height) + 40 # Padding 40

    img = Image.new('RGB', (img_width, img_height), color=BG_COLOR)
    d = ImageDraw.Draw(img)

    y_text = 20
    for line in lines:
        d.text((20, y_text), line, font=font, fill=TEXT_COLOR)
        y_text += line_height
        
    img.save(filename)
    return filename

def create_pdf():
    pdf = PDF()
    pdf.set_auto_page_break(auto=True, margin=15)

    for cpp_file, input_data in FILES:
        output = compile_and_run(cpp_file, input_data)
        
        # Simulate Console Interaction text
        exe_name = cpp_file.replace(".cpp", ".exe")
        console_text = f"E:\\Lab_Exam> g++ {cpp_file} -o {exe_name}\n"
        console_text += f"E:\\Lab_Exam> {exe_name}\n"
        
        # We need to reconstruct the visible interaction.
        # The program output usually includes prompts like "Enter string: ".
        # Since we capture stdout, it includes those prompts IF they were flushed.
        # However, standard input isn't echoed in captured output usually, so let's simulate it purely from output + our knowledge.
        
        # Actually, simpler is just to show the output as captured, 
        # but maybe prepend the command execution line for realism.
        console_text += output
        
        console_text += "\n\nE:\\Lab_Exam>" # Prompt at end

        image_filename = f"screenshot_{cpp_file}.png"
        create_console_image(console_text, image_filename)
        
        pdf.add_page()
        pdf.set_font("Arial", 'B', 14)
        pdf.cell(0, 10, f"Program: {cpp_file}", 0, 1, 'L')
        
        pdf.ln(5)
        pdf.set_font("Arial", '', 10)
        pdf.cell(0, 10, "Console Output:", 0, 1, 'L')
        
        # Fit image to page width
        pdf.image(image_filename, x=10, w=190)
        
        # Clean up text image
        os.remove(image_filename)

    pdf.output(PDF_OUTPUT)
    print(f"PDF generated: {PDF_OUTPUT}")

if __name__ == "__main__":
    create_pdf()
