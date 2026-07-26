#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - Creates a new dog.
 * @name: Dog's name.
 * @age: Dog's age.
 * @owner: Dog's owner.
 *
 * Return: Pointer to the new dog, or NULL on failure.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	int len_name = 0, len_owner = 0;
	int i;

	while (name[len_name] != '\0')
		len_name++;

	while (owner[len_owner] != '\0')
		len_owner++;

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	dog->name = malloc(sizeof(char) * (len_name + 1));
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}

	dog->owner = malloc(sizeof(char) * (len_owner + 1));
	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}

	for (i = 0; i <= len_name; i++)
		dog->name[i] = name[i];

	for (i = 0; i <= len_owner; i++)
		dog->owner[i] = owner[i];

	dog->age = age;

	return (dog);
}
