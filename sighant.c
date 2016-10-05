#include "sighant.h"
#include "mish.h"


int kill(pid_t pid, int sig);


void sigCatcherINT( int theSignal ) {
    
    if ( theSignal == SIGINT) {
        for(int currentPid = 0; currentPid<MAX_COMMANDS; currentPid++){
            if (pidArray[currentPid]!=0){
                kill(pidArray[currentPid], SIGINT);
            }
        }
    }
    return;
}


Sigfunc * mysignal(int signo, Sigfunc *func) {
    struct sigaction	act, oact;

    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    if (signo == SIGALRM) {
#ifdef	SA_INTERRUPT
        act.sa_flags |= SA_INTERRUPT;
#endif
    } else {
#ifdef	SA_RESTART
        act.sa_flags |= SA_RESTART;
#endif
    }
    if (sigaction(signo, &act, &oact) < 0)
        return(SIG_ERR);
    return(oact.sa_handler);
}