git status --ignored -s | grep '!! ' | cut -c4- | grep -o '[^/]*$'
