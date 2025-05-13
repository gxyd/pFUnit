import re

def remove_fortran_comments(input_file, output_file=None):
    cleaned_lines = []

    with open(input_file, 'r') as f:
        for line in f:
            stripped = line.lstrip()
            if stripped.startswith('!'):
                continue  # full-line comment, skip
            # Remove inline comment: everything after first "!" (if not in a string literal)
            line_no_inline_comment = re.split(r'(?<!["\'])!', line)[0].rstrip()
            if line_no_inline_comment.strip():  # skip if becomes empty
                cleaned_lines.append(line_no_inline_comment + '\n')

    # Write result
    target_file = output_file if output_file else input_file
    with open(target_file, 'w') as f:
        f.writelines(cleaned_lines)

remove_fortran_comments("new.f90")
