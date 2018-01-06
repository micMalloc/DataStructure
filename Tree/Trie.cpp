struct Trie {
	bool finish;
	Trie* next[10];
	
	Trie () : finish(false) {
		memset(next, 0, sizeof(next));
	}
	~Trie () {
		for (int i = 0; i < 26; ++ i) {
			if (next[i])
				delete next[i];
		}
	}

	void insert (const char* key) {
		if (*key == '\0') {
			finish = true;
		} else {
			int	curr = *key - '0';
			if (next[curr] == NULL) {
				next[curr] = new Trie();
			} next[curr]->insert(key + 1);
		}
	}

	bool find (const char* key) {
		if (*key == '\0') return this;
		int curr = *key - '0';
		if (next[curr] == NULL) return NULL;
		return next[curr]->find(key + 1);
	}
};