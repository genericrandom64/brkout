#include <rect.h>
#include <lc.h>

// Returns the overlapping section between the two rects
rect rect_overlap(rect* r1, rect* r2) {

	// SI = Max(0, Min(r1 right, r2 right) - Max(rect1 left, rect2 left)) * Max(0, Min(rect1 bottom, rect2 bottom) - Max(rect1 top, rect2 top))
	rect overlap;
	overlap.x = max(r1->x, r2->x);
	overlap.y = max(r1->y, r2->y);
	overlap.w = min(r1->x + r1->w, r2->x + r2->w) - max(r1->x, r2->x);
	overlap.h = min(r1->y + r1->h, r2->y + r2->h) - max(r1->y, r2->y);
	return overlap;

}