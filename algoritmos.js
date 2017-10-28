let algoritmoEuclidiano = (a, b) => {
    let resto = a % b;
    while (resto !== 0) {
        a = b;
        b = resto;
        resto = a % b;
    }
    return b;
};