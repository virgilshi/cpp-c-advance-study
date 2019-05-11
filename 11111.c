#include "stdio.h"
#include "stdlib.h"

typedef unsigned long long 	uint64_t;
typedef unsigned int 	uint32_t;

struct ftl_ppa {
	union {
		struct {
			uint64_t lbk	: 32;
			uint64_t chk	: 16;
			uint64_t pu	: 8;
			uint64_t grp	: 7;
			uint64_t rsvd	: 1;
		};

		struct {
			uint64_t offset	: 63;
			uint64_t cached : 1;
		};

		struct {
			union {
				struct  {
					uint32_t offset : 31;
					uint32_t cached : 1;
				};

				uint32_t ppa;
			};
			uint32_t rsvd;
		} pack;

		uint64_t ppa;
	};
};

 
 int main()
 {
		struct ftl_ppa p;
		uint64_t temp1, temp2, temp_a, temp_b, temp_c, temp_d;
		
		temp_a = p.lbk = 1;
		temp_b = p.chk = 1;
		temp_c = p.pu = 1;
		temp_d = p.grp = 1;
		
		temp1 = (p.grp << 56) | \
						(p.pu << 48) | \
		        (p.chk << 32) | \
		        p.lbk;
		
		temp2 = (temp_d << 56) | \
						(temp_c << 48) | \
		        (temp_b << 32) | \
		        temp_a;
		
		printf("%llx \n%ld \n", temp1, temp1);
		
		printf("%llx \n%lld \n", temp2, temp2);
		
		system("pause");
		
		return 0;
 }
