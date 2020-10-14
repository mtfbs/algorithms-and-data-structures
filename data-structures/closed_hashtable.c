/*
 * Time complexity:
 * 
 * medium case ($) -> 1/(1-alpha) for insertion
 *   ||    ||   |  -> (1/alpha) * log(1/(1-alpha)) for removal
 *
 * ($): 
 * (given alpha as the hashtable load factor [number of items/number of slots]
 *  and assuming simple uniform distribution of the items along the hashtable)
 * 
 */