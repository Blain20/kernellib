# include <kernel/kernel.h>
# include <kernel/net.h>
# include <kernel/user.h>

inherit LIB_PORT;

/*
 * NAME:	create()
 * DESCRIPTION:	initialize port object
 */
static void create(int clone)
{
    if (clone) {
	::create();
    }
}

/*
 * NAME:	listen()
 * DESCRIPTION:	start listening on a port
 */
void listen(string protocol, int port)
{
    if (previous_program() == USERD) {
	if (!open_port(protocol, port)) {
	    DRIVER->message("open_port(" + protocol + ", " + port +
				       ") failed!\n");
	}
    }
}

/*
 * NAME:	open_connection()
 * DESCRIPTION:	don't return a user object, select it by first line of input
 */
static object open_connection(string ipaddr, int port)
{
    return nil;
}
