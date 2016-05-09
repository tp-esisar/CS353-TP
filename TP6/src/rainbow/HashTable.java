package rainbow;

import java.io.Serializable;

public class HashTable implements Serializable {
	private static final long serialVersionUID = 1L;
	private Noeud[] table;
	
	public HashTable(int taille) {
		table = new Noeud[taille];
		for (int i=0; i<table.length; i++) {
			table[i]= new Noeud();
			table[i].setP999(-1);
		}			
	}
	
	public boolean insert(int p999, int px) {
		int indice, i=0;
		
		do {
			indice = h(p999, i++);
			
			if (table[indice].getP999() == p999 || i>999)
				return false;
			
		}while (table[indice].getP999() != -1);
		
		table[indice].setP999(p999);
		table[indice].setPX(px);
		return true;
	}
	
	private int h(int cle, int i) {
		int h1 = cle % table.length;
		int h2 = 1 + (cle % (table.length-1));		
		return (h1 + i*h2) % table.length;	
	}
	
	public int acces (int cle) {
		int indice, i=0;
		do {
			indice = h(cle, i++);
			
			if (table[indice].getP999() == cle)
				return table[indice].getPX();
			
		} while (table[indice].getP999() != -1 || i<1000);
		return -1;
	}
	
	public int get (int indice) {
		return table[indice].getPX();
	}

}
