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
		return true;
	}
	
	
	
	
	
}
