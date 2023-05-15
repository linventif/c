#!/bin/bash

# Récupère la liste des fichiers exécutables dans le dossier courant
executable_files=$(find . -type f -executable)

# Parcourt chaque fichier exécutable
for file in $executable_files; do
    # Vérifie si le fichier est un fichier exécutable
    if [ -x "$file" ]; then
        # Supprime le fichier exécutable
        rm "$file"
        echo "Fichier supprimé : $file"
    fi
done
