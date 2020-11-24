#pragma once

namespace NPair {
	template<typename K>
	struct TPair {
		TPair() : Key(0) {
			Str[65] = { 0 };
		}

		TPair(K key, char* v) : Key(key) {
			for (int i = 0; i < 65; ++i) {
				Str[i] = v[i];
			}
		}

		~TPair() {}

		bool operator<(const TPair& other) const {
			return Key < other.Key;
		}

		TPair& operator=(const TPair& other) {
			Key = other.Key;
			for (int i = 0; i < 65; ++i) {
				Str[i] = other.Str[i];
			}
			return *this;
		}
		K Key;
		char Str[65];
	};

}