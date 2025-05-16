from pathlib import Path

def remove_full_line_comments(filepath: str):
    path = Path(filepath)

    with path.open('r', encoding='utf-8') as f:
        lines = f.readlines()

    cleaned_lines = [
        line for line in lines
        if not line.lstrip().startswith('!')
    ]

    with path.open('w', encoding='utf-8') as f:
        f.writelines(cleaned_lines)

    print(f"Cleaned: {filepath}")

# Example usage
remove_full_line_comments("./extern/fArgParse/extern/gFTL-shared/extern/gFTL/include/v2/stack/procedures.inc")
remove_full_line_comments("./extern/fArgParse/extern/gFTL-shared/extern/gFTL/include/v2/deque/iterator_procedures.inc")
remove_full_line_comments("./extern/fArgParse/extern/gFTL-shared/extern/gFTL/include/v2/deque/procedures.inc")
remove_full_line_comments("./extern/fArgParse/extern/gFTL-shared/extern/gFTL/include/v2/deque/specification.inc")
remove_full_line_comments("./extern/fArgParse/extern/gFTL-shared/extern/gFTL/include/v2/queue/procedures.inc")
remove_full_line_comments("./extern/fArgParse/extern/gFTL-shared/extern/gFTL/include/v2/stack/procedures.inc")
