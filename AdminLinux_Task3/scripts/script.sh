#!/bin/bash

# Define the path to the .bashrc file in the user's home directory
BASHRC_FILE="$HOME/.bashrc"

# Check if the .bashrc file exists
if [ -f "$BASHRC_FILE" ]; then
    # Append environment variables to the .bashrc file
    echo "export HELLO=\${HOSTNAME}" >> ${BASHRC_FILE}
    echo "export LOCAL=\$(whoami)" >> ${BASHRC_FILE}
    echo "Environment variables HELLO and LOCAL have been added to .bashrc."
  
  else
    echo ".bashrc not found in the home directory."
fi

# for wsl -->
cmd.exe /c start wsl 

# for ubuntu -->
# gnome-terminal
