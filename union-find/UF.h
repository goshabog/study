/*
 * UF.h
 *
 *  Created on: 27 окт. 2019 г.
 *      Author: gosha
 */

#ifndef UF_H_
#define UF_H_

class UF {
public:
	UF(int N);  // initialize union-find data structure with N objects (0 to N Ц 1)
	void connection(int p, int q);  // add connection between p and q
	bool isConnected(int p, int q); // are p and q in the same component?
	int find(int p); // component identifier for p (0 to N Ц 1)
	int count(); // number of components
};

#endif /* UF_H_ */
