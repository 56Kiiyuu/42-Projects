#!/bin/bash

# Fonction pour tester une commande
run_test() {
    echo -e "\n--- Test : $1 ---"
    echo "Attendu (bash) :"
    eval "$1"
    echo -e "\nVotre Microshell :"
    ./microshell $1
}

# 1. Tests simples
run_test "/bin/ls"
run_test "/bin/ls -l"

# 2. Tests avec Pipes
run_test "/bin/ls | /usr/bin/grep microshell"
run_test "/bin/ls | /usr/bin/grep microshell | /usr/bin/cat"

# 3. Tests avec Semicolon
run_test "/bin/ls ; /bin/echo 'fini'"

# 4. Tests mixtes (Le plus important)
# Attention, il faut bien passer "|" et ";" comme arguments si tu les mets entre guillemets
# (selon comment ton main gère le parsing, mais en général on utilise des quotes pour éviter que le bash ne les interprète avant)
./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo "fini"

# 5. Tests cd (Attention aux messages d'erreur)
echo -e "\n--- Test : cd ---"
./microshell cd /tmp ";" /bin/pwd
./microshell cd "un_dossier_qui_n_existe_pas"
./microshell cd a b c

# Génère une commande avec 50 pipes
cmd="/bin/ls"
for i in {1..50}; do cmd="$cmd '|' /usr/bin/grep a"; done
./microshell $cmd
