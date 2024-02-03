
/**
 * @param {number[][]} points
 * @return {number}
 */
var numberOfPairs = function (points) {

    points.sort((first, second) => comparator_decreasingOrder_yCoordinates(first, second));

    this.points = points;
    let countNumberOfPairs = 0;

    for (let first = 0; first < points.length; ++first) {
        for (let second = first + 1; second < points.length; ++second) {

            if (points[first][0] > points[second][0]) {
                continue;
            }

            let firstAndSecondMakePair = true;

            for (let middle = first + 1; middle < second; ++middle) {
                if (middlePoint_isOnTheFence_or_withinTheFencedArea(first, second, middle)) {
                    firstAndSecondMakePair = false;
                    break;
                }
            }
            countNumberOfPairs += firstAndSecondMakePair ? 1 : 0;
        }
    }
    return countNumberOfPairs;
};

/**
 * @param {number} firstIndex
 * @param {number} secondIndex
 * @param {number} middleIndex
 * @return {boolean}
 */
function middlePoint_isOnTheFence_or_withinTheFencedArea(firstIndex, secondIndex, middleIndex) {
    return this.points[middleIndex][0] >= this.points[firstIndex][0]
            && this.points[middleIndex][0] <= this.points[secondIndex][0]
            && this.points[middleIndex][1] >= this.points[secondIndex][1]
            && this.points[middleIndex][1] <= this.points[firstIndex][1];
}

/**
 * @param {number[]} firstPoint
 * @param {number[]} secondPoint
 * @return {number}
 */
function comparator_decreasingOrder_yCoordinates(firstPoint, secondPoint) {
    return (secondPoint[1] === firstPoint[1])
            ? (firstPoint[0] - secondPoint[0])
            : (secondPoint[1] - firstPoint[1]);
}
