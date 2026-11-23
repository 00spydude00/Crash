# What is this?

Crush is a shell. It has minimal features, and is not meant for production use.

This project (as of now) is meant for my own learning and experience.

# How does it work?

At a high level, this program takes in input from fgets(), parses it with strtok(), and passes those tokens as arguments for execvp() in a child process with fork().

# How can I use it?

First, you must compile 'crush.c' into binary. I recommend gcc (Gnu C Compiler) if you are on a Unix-like operating system.

Then, simply execute from the name of the output file and voila! You have yourself a working shell

# What is missing?

Crush is missing a load of things, like file compatability (scripting), which I don't know if I will ever implement, but it could be a fun project.

Crush, as of now, also limits the total character count of a command to 30, and also limits total arguments to 10, though that will likely change.

If you want to make a PR or an Issue, feel free.
