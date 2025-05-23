#define NOFILE 16
typedef unsigned int uint;


// Context saved during a context switch
struct context {
    int eip;
    int esp;
    int ebx;
    int ecx;
    int edx;
    int esi;
    int edi;
    int ebp;
};

// Possible states of a process
enum proc_state {
    UNUSED,
    EMBRYO,
    SLEEPING,
    RUNNABLE,
    RUNNING,
    ZOMBIE
};

// Process control block
struct proc {
    char *mem;                     // Start of process memory
    uint sz;                       // Size of process memory
    char *kstack;                  // Bottom of kernel stack for this process
    enum proc_state state;        // Process state
    int pid;                       // Process ID
    struct proc *parent;          // Parent process
    void *chan;                   // If non-zero, sleeping on chan
    int killed;                   // If non-zero, have been killed
    struct file *ofile[NOFILE];   // Open files
    struct inode *cwd;            // Current directory
    struct context context;       // Switch here to run process
    struct trapframe *tf;         // Trap frame for the current interrupt
};
