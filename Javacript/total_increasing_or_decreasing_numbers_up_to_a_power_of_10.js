function cwr(n, k) {
	var ret = 1 
	for (var i = 1; i <= k; i+= 1) ret *= (n + k - 1)/i 
		return Math.round(ret)
}

function totalIncDec(x){
	return cwr(10, x) + cwr(11, x) -1 -x * 10
}