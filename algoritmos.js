let divisao = (a, b) => {
    let q = 0;
    let r = a;
    while (r >= b) {
        r -= b;
        q++;
    }
    return {quociente: q, resto: r};
};