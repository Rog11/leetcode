function differentiate( equation, point ) {
	const standarize = equation => {
		return equation
		.replace(/(?<=^\+|-)(?=x)/g, "1")
		.replace(/(?<=\d+)$/, "x^0")
		.replace(/x(?=\+|-|$)/, "x^1")
		.split(/\+|(?=-)/)
		.map(term => term.split( /x\^/));
	};
	const derivative = ([coeff, exp]) => [coeff*exp, exp- 1]; 
	const evaluate = (sum, [coeff, exp]) => sum + coeff * point**exp; 
	return standarize(equation).map(derivative).reduce(evalute, 0);  
}
