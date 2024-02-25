int a, b, topo=0;

int pilha[1000];

void push(int valor) {
	pilha[topo++] = valor;
}

int pop() {
	return pilha[--topo];
}
