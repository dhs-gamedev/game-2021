set -e

if [[ -e build ]]; then
  if [[ ! -d build ]]; then
    echo "Build exists, and is not a directory!" >&2
  fi
else
  mkdir build
fi

cmake -S . -B build/
cmake --build build/
