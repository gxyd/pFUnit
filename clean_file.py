import re

def clean_file(input_file, output_file=None):
    # Matches lines like: # 123 "/path/to/file"
    hash_line_pattern = re.compile(r'^# \d+ .+')

    with open(input_file, 'r') as f:
        lines = f.readlines()

    cleaned_lines = [
        line for line in lines
        if not hash_line_pattern.match(line) and line.strip() != ''
    ]

    target_file = output_file if output_file else input_file
    with open(target_file, 'w') as f:
        f.writelines(cleaned_lines)

clean_file("new.f90")
