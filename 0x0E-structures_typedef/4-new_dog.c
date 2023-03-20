#include "dog.h"
#include <stdlib.h>

/**
  * new_dog - creates a new dog
  * @name: dog's name
  * @age: dog's age
  * @owner: dog's owner
  * Return: NULL if the function fails
  */

dog_t *new_dog(char *name, float age, char *owner)
{
	int newdog, olddog, i;
	dog_t *puppy;

	newdog = olddog = 0;
	while (name[newdog++])
		;
	while (owner[olddog++])
		;
	puppy = malloc(sizeof(dog_t));
	if (puppy == NULL)
		return (NULL);

	puppy->name = malloc(newdog * sizeof(puppy->name));
	if (puppy == NULL)
		return (NULL);
	for (i = 0; i < newdog; i++)
		puppy->name[i] = name[i];

	puppy->age = age;

	puppy->owner = malloc(olddog * sizeof(puppy->owner));
	if (puppy == NULL)
		return (NULL);
	for (i = 0; i < olddog; i++)
		puppy->owner[i] = owner[i];
	return (puppy);
}
