//shortest knight path 

function moveSearch(position, target) {
    let stack = []; // maintain an ordered stack so that we choose the 'best first'

    stack.push({position: positionToArray(position), moves: []});
    while (stack.length !== 0) {
        let move = stack.pop();
        let position = move.position;

        // If the current position is the target, then we're done and we can send back the moves we've
        // taken
        if (arrayToPosition(move.position) === target) {
            return [...move.moves, position].map(arrayToPosition);
        }

        // Otherwise, we need to get the candidate moves from this list, and place them on the stack
        pruneMoves(position)
            .map(move => {
                // Apply the move
                let rank = position[0] + move[0];
                let file = position[1] + move[1];

                return [rank, file];
            })
            .forEach(item => {
                // Don't allow doubling back
                if (move.moves.map(arrayToPosition).includes(arrayToPosition(item))) {
                    return;
                }

                // Push the move to the stack
                stack.push({position: item, moves: [...move.moves, position]});
            });

        // Check the candidate with the fewest moves so far, otherwise choose the one
        // that's closest
        stack.sort((a, b) => {
            if (a.moves.length !== b.moves.length) {
                return  b.moves.length - a.moves.length;
            }

            let aDistance = calculateDistance(a.position, positionToArray(target));
            let bDistance = calculateDistance(b.position, positionToArray(target));

            return bDistance - aDistance;
        });
    }

    // we shouldn't really reach here -- this signifies that it's impossible
    return [];
}

/**
 * Takes all the available knight moves, and return the ones that keep it on the board
 *
 * @param position
 * @returns {*[]}
 */
function pruneMoves(position) {
    return allMoves.filter((move) => {
        let rank = position[0] + move[0];
        let file = position[1] + move[1];

        return rank >= 0 && rank < ranks.length && file >= 0 && file < files.length;
    });
}

/**
 * Converts a chess position to an array
 *
 * @param move
 * @returns {*[]}
 */
function positionToArray(move) {
    let chars = move.split('');
    return [
        ranks.indexOf(chars[0]),
        files.indexOf(chars[1])
    ];
}

/**
 * Converts an array to a chess position
 *
 * @param arr
 * @returns {string}
 */
function arrayToPosition(arr) {
    return ranks[arr[0]] + files[arr[1]];
}

/**
 * Calculates the distance between two positions
 * @param pos1 array the first position
 * @param pos2 array the second position
 * @returns {number} the distance between the two positions
 */
function calculateDistance(pos1, pos2) {
    // Take the euclidean distance using a2 + b2 = c2
    let rankDistance = pos1[0] - pos2[0];
    let fileDistance = pos1[1] - pos2[1];

    return Math.sqrt(Math.pow(rankDistance, 2) + Math.pow(fileDistance, 2));
}