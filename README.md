# Ordenacao-TDE3-Andrey

Vetores utilizados: 
vetor1 = {12, 18, 9, 25, 17, 31, 22, 27, 16, 13, 19, 23, 20, 30, 14, 11, 15, 24, 26, 28}
vetor2 = {5, 7, 9, 10, 12, 14, 15, 17, 19, 21, 22, 23, 24, 25, 27, 28, 29, 30, 31, 32}
vetor3 = {99, 85, 73, 60, 50, 40, 35, 30, 25, 20, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6}

Tabela quem fez menos trocas
1ºlugar: Bucket Sort – média de 20 trocas. Foi o melhor em todos os vetores, principalmente no ordenado e no aleatório.
2lugar: Comb Sort – média de 40 trocas. Teve ótimo desempenho no vetor bagunçado.
3ºlugar: Selection Sort – 19 trocas. Fez poucas trocas, mas teve muitas comparações.
4ºlugar: Gnome Sort – 65 trocas. Teve resultado razoável, porém mais lento.
5ºlugar: Cocktail Sort – 82 trocas. Melhor que o Bubble, mas ainda com muitas trocas.
6ºlugar: Bubble Sort – 90 trocas. Pior desempenho geral nesse quesito.

Tabela quem fez menos comparações

1ºlugar: Comb Sort – média de 110 comparações. Melhor nos vetores bagunçados e invertidos.
2ºlugar: Bucket Sort – média de 80 comparações. Muito bom em vetores pequenos e bem distribuídos.
3ºlugar: Cocktail Sort – média de 175 comparações. Razoável, mas ainda alto em vetores grandes.
4ºlugar: Gnome Sort – média de 140 comparações. Desempenho intermediário.
5ºlugar: Selection Sort – média de 190 comparações. Igual ao Bubble, mas com menos trocas.
6ºlugar: Bubble Sort – média de 190 comparações. Pior resultado no total de iterações.

Tabela de melhor algoritmo para cada tipo de vetor

Vetor bagunçado (vetor1): Comb Sort – equilibrou bem comparações e trocas.
Vetor ordenado (vetor2): Bucket Sort – já quase ordenado, precisou de poucas operações.
Vetor invertido (vetor3): Bucket Sort – manteve bom desempenho mesmo na pior situação.

