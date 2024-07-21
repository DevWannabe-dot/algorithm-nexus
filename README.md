<!-- Index -->
# algorithm-nexus
Multiple algorithms I've wrote on top of my study routine, in order to help demonstrate or even solve different branches of general problems, using computer science.

<!-- Preview -->
<p align="center">
    <img src=".media/game_preview.gif" width=300px>
</p><br>

<!-- Usage -->
# Usage
Reading the internal source code documentation is advised.
#### analyticDecompositionV.c
`$ gcc analyticDecompositionV.c -lm -oanalyticDecompositionV`<br>
`$ ./analyticDecompositionV compose 30 40`<br>
`$ ./analyticDecompositionV decompose 130 67.5`<br>
#### primeFactorDecomposition.c
`$ gcc primeFactorDecomposition.c -lm -oprimeFactorDecomposition`<br>
`$ ./primeFactorDecomposition 770`<br>
#### generateMegaSena.c
`$ gcc generateMegaSena.c -ogenerateMegaSena`<br>
`$ ./generateMegaSena 6 60`<br>
#### xor_swap.c
`$ gcc xor_swap.c -lm -oxor_swap`<br>
`$ ./xor_swap 8 80`<br>
#### bit_shift.cpp
`$ g++ bit_shift.cpp -obit_shift`<br>
`$ ./bit_shift`
<!-- #### ITA-escolha-de-especialidade.cpp
`$ g++ ITA-escolha-de-especialidade.cpp`<br>
`$ ./a.out`<br> -->
#### squareDigitSum.cpp
`$ g++ squareDigitSum.cpp -osquareDigitSum`<br>
`$ ./squareDigitSum`<br>
#### game.pde
Run [Processing](https://processing.org/download), open the source file and debug. Any `keyPressed` signal while window is `focused` should update the cellular automata.
#### euclidAlgorithm.cpp
`$ g++ -DEXTERN_XOR_SWAP euclidAlgorithm.cpp xor_swap.c -lm -oeuclidAlgorithm`<br>
`$ ./euclidAlgorithm 162 372`<br>
