#!/bin/bash

# Récupère la liste des fichiers C dans le dossier courant
c_files=$(find . -type f -name "*.c")

# Compile chaque fichier C
for file in $c_files; do
    # Récupère le nom du fichier sans l'extension
    filename=$(basename "$file" .c)

    # Compile le fichier C en utilisant gcc
    gcc -Wall -o "$filename" "$file"

    # Vérifie si la compilation a réussi
    if [ $? -eq 0 ]; then
        echo "Compilation réussie : $filename"
    else
        echo "Échec de la compilation : $filename"
    fi
done
