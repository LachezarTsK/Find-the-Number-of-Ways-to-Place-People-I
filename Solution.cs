
using System;

public class Solution
{
    private int[][] points;
    public int NumberOfPairs(int[][] points)
    {
        Array.Sort(points, (first, second) => Comparator_decreasingOrder_yCoordinates(first, second));

        this.points = points;
        int countNumberOfPairs = 0;

        for (int first = 0; first < points.Length; ++first)
        {
            for (int second = first + 1; second < points.Length; ++second)
            {

                if (points[first][0] > points[second][0])
                {
                    continue;
                }

                bool firstAndSecondMakePair = true;

                for (int middle = first + 1; middle < second; ++middle)
                {
                    if (MiddlePoint_isOnTheFence_or_withinTheFencedArea(first, second, middle))
                    {
                        firstAndSecondMakePair = false;
                        break;
                    }
                }
                countNumberOfPairs += firstAndSecondMakePair ? 1 : 0;
            }
        }
        return countNumberOfPairs;
    }

    private bool MiddlePoint_isOnTheFence_or_withinTheFencedArea(int firstIndex, int secondIndex, int middleIndex)
    {
        return points[middleIndex][0] >= points[firstIndex][0]
                && points[middleIndex][0] <= points[secondIndex][0]
                && points[middleIndex][1] >= points[secondIndex][1]
                && points[middleIndex][1] <= points[firstIndex][1];
    }

    private int Comparator_decreasingOrder_yCoordinates(int[] firstPoint, int[] secondPoint)
    {
        return (secondPoint[1] == firstPoint[1])
                ? (firstPoint[0] - secondPoint[0])
                : (secondPoint[1] - firstPoint[1]);
    }
}
