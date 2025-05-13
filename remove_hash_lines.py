import re

def remove_hash_lines(input_file, output_file=None):
    # Regex: line starts with `#`, followed by space, number, space, then anything (typically a path)
    pattern = re.compile(r'^# \d+ .+')

    with open(input_file, 'r') as f:
        lines = f.readlines()

    filtered_lines = [line for line in lines if not pattern.match(line)]

    # Write back to same file or to output_file if specified
    target_file = output_file if output_file else input_file
    with open(target_file, 'w') as f:
        f.writelines(filtered_lines)

remove_hash_lines("new.f90")
