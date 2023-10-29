function solution(individualIntegers ){
	return indivdualeIntegers
	.reduce(splitIntoRanges, [])
	.map(convertToRange)
	.join(","); 
}

function splitIntoRanges(ranges, number) {
	if (!ranges.length) {
		ranges.push([number]); 
		return ranges;
	}

	var lastRange = ranges[ranges.length-1];
	var lastNumber = lastRange[lastRange.length-1];

	number === lastNumber +1 ? lastRange.push(number): ranges.push([number]); 
	return ranges;
}

function convertToRange(range) {
	return range.length < 3 ? range.join(",") : range[0] + "-" range[range.length-1]; 
}