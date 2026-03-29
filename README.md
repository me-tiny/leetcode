# leetcode templating script

## usage

### starting new problem

```bash
./new <problem-number> <problem-name>
# example
./new 217 contains-duplicate
```

### run solution

```bash
make run F=problems/0217-contains-duplicate/sol.cpp
# or with sanitisers
make run F=problems/0217-contains-duplicate/sol.cpp D=1
```

### scripts

> [!NOTE]
> these have to be run in the root directory

#### `lc`

compiles and runs the last edited solution

#### `lcd`

compiles and runs the last edited solution with sanitisers

#### `lcs`

lists all problems with solution files

#### aliasing

these scripts can also be aliased and sourced through zsh/bash

```zsh
lc() {
  local file="${1:-$(find problems -name 'sol.cpp' -printf '%T@ %p\n' | sort -rn | head -1 | cut -d' ' -f2)}"
  if [ -z "$file" ]; then
    echo "no solution files found"
    return 1
  fi
  echo "── Running: $file ──"
  make run F="$file" "${@:2}"
}

lcd() {
  local file="${1:-$(find problems -name 'sol.cpp' -printf '%T@ %p\n' | sort -rn | head -1 | cut -d' ' -f2)}"
  make run F="$file" D=1
}

lcs() {
  ls -d problems/*/ 2>/dev/null | sed 's|problems/||;s|/||' | column
}
```
