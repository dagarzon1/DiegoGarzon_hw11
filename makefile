vel.png pos.png phase.png:tray.txt
	python DG_graph.py
	rm tray.txt
tray.txt:DG_gravity.x
	./DG_gravity.x > tray.txt
	rm DG_gravity.x
DG_gravity.x:
	c++ DG_gravity.cpp -o DG_gravity.x
clean:
	rm vel.png pos.png phase.png
