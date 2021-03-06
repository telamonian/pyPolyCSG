# example of cylinder primitive
# James Gregson (james.gregson@gmail.com), March 2013

# import module
import pyPolyCSG as csg

# create a cylinder with radius 0.5 and height 2, centered on origin
# with 100 sides
cyl = csg.cylinder( 0.5, 2.0, True, 100 )

tmp = csg.polyhedron()
tmp.make_cylinder( 0.5, 2.0, True, 50 )
tmp.save_mesh("output/cylinder2.obj")

# save result as box.obj
cyl.save_mesh( "output/cylinder.obj" )
