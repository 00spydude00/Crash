# what is this?

Crush is a shell. It has minimal features, and is not meant for production use.

This project (as of now) is meant for my own learning and experience.

# How does it work?

At a high level, this program takes in input from fgets(), parses it with strtok(), and passes those tokens as arguments for execvp() in a child process with fork().
