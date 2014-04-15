/*

DO NOT edit this file

*/
#ifndef DYCKCFL_TERMS_H
#define DYCKCFL_TERMS_H
#include "list.h"
#include <stdio.h>
#include "bool.h"
#include "linkage.h"
#include "hash.h"

EXTERN_C_BEGIN

typedef struct node_T_* node_T;

extern int flag_hash_cons;
extern bool flag_merge_projections;
extern bool flag_eliminate_cycles;
DECLARE_LIST(node_T_list,node_T);
node_T node_T_zero(void);
node_T node_T_one(void);
node_T node_T_wild(void);
INT_PTR node_T_get_stamp(node_T e);
node_T node_T_fresh(const char *name);
node_T node_T_union(node_T_list exprs);
node_T node_T_inter(node_T_list exprs);
node_T node_T_constant(const char *name);
bool node_T_eq(node_T e1, node_T e2);
int node_T_cmp(const node_T e1,const node_T e2);
bool node_T_is_constant(node_T e,const char *name);
void node_T_inclusion(node_T e1,node_T e2);
void node_T_unify(node_T e1,node_T e2);
node_T_list node_T_tlb(node_T e);

struct OPos_decon
{
int index;
node_T f0;
};
struct NGroup_decon
{
node_T f0;
};
bool node_T_is_OPos(node_T e, int index);
node_T OPos(int arg1,node_T arg2);
bool node_T_is_NGroup(node_T e);
node_T NGroup(node_T arg1);
struct OPos_decon OPos_decon(node_T arg1);
struct NGroup_decon NGroup_decon(node_T arg1);
node_T NGroup_pat0(node_T arg1);
node_T OPos_proj0(node_T arg1, int index);
node_T OPos_pat0(node_T arg1,int arg2);
struct ONeg_decon
{
int index;
node_T f0;
};
struct NContraGroup_decon
{
node_T f0;
};
bool node_T_is_ONeg(node_T e, int index);
node_T ONeg(int arg1,node_T arg2);
bool node_T_is_NContraGroup(node_T e);
node_T NContraGroup(node_T arg1);
struct ONeg_decon ONeg_decon(node_T arg1);
struct NContraGroup_decon NContraGroup_decon(node_T arg1);
node_T NContraGroup_pat0(node_T arg1);
node_T ONeg_proj0(node_T arg1, int index);
node_T ONeg_pat0(node_T arg1,int arg2);
bool node_T_is_Pos(node_T e);
node_T Pos(node_T arg1);
struct Pos_decon Pos_decon(node_T arg1);
struct Pos_decon
{
node_T f0;
};
node_T Pos_proj0(node_T arg1);
node_T Pos_pat0(node_T arg1);
void node_T_print(FILE* arg1,node_T arg2);
/*

Init/reset engine, print constraint graphs, serialize/deserialize constraint graphs

*/
void dyckcfl_terms_init(void);
void dyckcfl_terms_reset(void);
void dyckcfl_terms_stats(FILE * arg1);
void dyckcfl_terms_print_graph(FILE * arg1);
void dyckcfl_terms_serialize(FILE * arg1,hash_table * arg2,unsigned long arg3);
hash_table * dyckcfl_terms_deserialize(FILE * arg1);
void dyckcfl_terms_region_serialize(FILE * arg1);
void dyckcfl_terms_region_deserialize(translation arg1,FILE * arg2);
EXTERN_C_END
#endif
