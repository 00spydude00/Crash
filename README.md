# What is this?

Crush is a shell. It has minimal features, and is not meant for production use.

This project (as of now) is meant for my own learning and experience.

# How does it work?

At a high level, this program takes in input from fgets(), parses it with strtok(), and passes those tokens as arguments for execvp() in a child process with fork().

# How can I use it?

First, you must compile 'crush.c' into binary. I recommend gcc (Gnu C Compiler) if you are on a Unix-like operating system.

Then, simply execute from the name of the output file and voila! You have yourself a working shell

# What is missing?

The absolute most important thing that this shell is missing as of now is a command to change your directory. I might have that implemented soon, but I also want to get on to other things.

Crush is also missing a load of other things, like file compatability (scripting), which I don't know if I will ever implement, but it could be a fun project.

If you want to make a PR or an Issue, feel free.
