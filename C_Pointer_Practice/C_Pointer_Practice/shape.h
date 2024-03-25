#pragma once
#ifndef SHAPE_H_INCLUDE
#define SHAPE_H_INCLUDE

typedef enum {
	FALSE = 0,
	TRUE = 1
}Boolean;

typedef struct {
	int red;
	int green;
	int blue;
}Color;

typedef enum {
	FILL_NONE,	//“h‚è‚Â‚Ô‚³‚È‚¢
	FILL_SOLID	//“h‚è‚Â‚Ô‚µ
}FillPattern;

typedef enum {
	POLYLINE_PRIMITIVE,
	RECTANGLE_PRIMITIVE,
	ELLIPSE_PRIMITIVE
}PrimitiveType;

typedef struct {
	double x;
	double y;
}Point;

typedef struct {
	int npoints;
	Point* point;
}Polylie;

typedef struct {
	Point min_point;
	Point max_point;
}Rectangle;

typedef struct {
	Point center;
	double h_radius;
	double v_radius;
}Ellipse;

typedef struct {
	PrimitiveType type;
	Color line_color;
	FillPattern fill_pattern;
	Color fill_color;

	union {
		Polylie polyline;
		Rectangle rectangle;
		Ellipse ellipse;
	}u;
}Primitive;


typedef struct Shape_tag Shape;

typedef struct {
	Shape* head;
	Shape* tail;
}Group;

typedef enum {
	PRIMITIVE_SHAPE,
	GROUP_SHAPE
}ShapeType;

struct Shape_tag {
	ShapeType type;
	Boolean selected;
	union {
		Primitive primitive;
		Group group;
	}u;

	struct Shape_tag* prev;
	struct Shape_tag* next;
};





#endif