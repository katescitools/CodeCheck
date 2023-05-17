// Given a pointer to a message, check the message header and return
// a pointer to the body of the message or NULL if the message is
// invalid.
const char_t *msg_body ( const char_t * msg )
{
const char_t * body = NULL;
	if ( msg != NULL )
	{
		if ( msg_header_valid ( msg ) )
		{
			body = &msg [ MSG_HEADER_SIZE ];
		}
	}
	return ( body );
}
// ...
char_t msg_buffer [ MAX_MSG_SIZE ];
const char_t * payload;
// ...
payload = msg_body ( msg_buffer );
if ( payload != NULL )
{
	// process the message payload
}