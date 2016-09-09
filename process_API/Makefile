all: fork noise fork_exec fork_redirect fork_redirect_exec

fork: fork.c
	$(CC) -g -O3 fork.c -o fork
#	objdump -D fork > fork.dump
fork_redirect: fork_redirect.c noise
	$(CC) -g -O3 fork_redirect.c -o fork_redirect

fork_exec: fork.c noise
	$(CC) -g -O3 -DEXEC fork.c -o fork_exec

fork_redirect_exec: fork_redirect.c noise
	$(CC) -g -O3 -DFORKEXEC fork_redirect.c -o fork_redirect_exec


noise: noise.c
	$(CC) -g -O3 noise.c -o noise


clean:
	rm -f fork noise fork_exec
