#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


long int* tri_shaker(size_t size, long int* const array)
{
	int sup = size - 1;
	int inf = 0;
	bool b = true;
	while (b)
	{
		b = false;
		int i;
		for (i = inf; i <= sup - 1; i++) if (array[i]>array[i + 1])
		{
			int buff = array[i]; array[i] = array[i + 1]; array[i + 1] = buff;
			b = true;
		}

		sup--;
		for (i = sup - 1; i >= inf; i--) if (array[i]>array[i + 1])
		{
			int buff = array[i]; array[i] = array[i + 1]; array[i + 1] = buff;
			b = true;
		}
		inf++;
	}  
	return array;
}


int main()
{
	long int tab[6] = {4, 8, 2, 3, 5, 8};
	size_t taille = 6;
	tri_shaker(taille, tab);
	
	for (size_t i = 0; i < taille; ++i)
    { 
        printf("%ld",tab[i]); 
    }
    // => 234588
    
    return EXIT_SUCCESS;
	
}

// Complexité dans le pire cas et le cas moyen : O(n²)
// Complexité dans le meilleur des cas : O(n)
// On peut aussi dire que (en raccourci) que O représente le pire des cas, Ω représente le meilleur des cas et Θ représente le cas moyen.
// => La complexité dans le pire des cas du tri shaker est AU PLUS O(n²)
// => La complexité dans le pire des cas du tri shaker est AU MOINS Ω(n)
// => La complexité dans le pire des cas du tri shaker est EXACTEMENT Θ(n²)


