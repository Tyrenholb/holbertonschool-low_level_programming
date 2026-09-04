#include <stdlib.h>
#include <string.h>
#include "session.h"

session_t *session_create(const char *id, unsigned int uid,
	const unsigned char *data, size_t data_len)
{
	session_t *s;
	size_t id_len;

	if (!id || (data_len > 0 && !data))
		return (NULL);

	s = malloc(sizeof(*s));
	if (!s)
		return (NULL);

	id_len = strlen(id);
	s->id = malloc(id_len + 1);
	if (!s->id)
	{
		free(s);
		return (NULL);
	}

	memcpy(s->id, id, id_len + 1);
	s->uid = uid;
	s->data = NULL;
	s->data_len = 0;

	if (data_len > 0)
	{
		s->data = malloc(data_len);
		if (!s->data)
		{
			free(s->id);
			free(s);
			return (NULL);
		}

		memcpy(s->data, data, data_len);
		s->data_len = data_len;
	}

	return (s);
}

int session_set_data(session_t *s, const unsigned char *data, size_t data_len)
{
	unsigned char *tmp;

	if (!s)
		return 0;

	if (data_len == 0) {
		free(s->data);
		s->data = NULL;
		s->data_len = 0;
		return 1;
	}

	tmp = (unsigned char *)realloc(s->data, data_len);
	s->data = tmp;

	if (!s->data) {
		s->data_len = 0;
		return 0;
	}

	memcpy(s->data, data, data_len);
	s->data_len = data_len;
	return 1;
}

void session_destroy(session_t *s)
{
	if (!s)
		return;

	free(s->id);

	free(s->data);
	free(s);
}
