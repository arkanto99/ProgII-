float potencia(int base, int exponente) { /*la funcion debe ser float potencia, ya que en el caso de exponente<0 se devuelve un numero decimal*/
    float valor = 1; 
    int i;
    for (i=1; i <= absoluto(exponente); i++) /*debe empezarse en i=1*/
        valor = valor * base;    
    return (exponente<0)? 1/valor : valor;
}

int absoluto(int n) {
    return (n<0)? -n : n; /*cambiei o primeiro "n" por "-n",xa que estábase devolvendo sempre o mesmo valor*/
}