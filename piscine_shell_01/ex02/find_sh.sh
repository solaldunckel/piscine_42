find . -type f -name "*.sh" | grep -o '[^/]*$' | rev | cut -c 4- | rev
