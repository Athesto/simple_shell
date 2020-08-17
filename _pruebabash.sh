#!/bin/bash
msg128="Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed lacinia bibendum lorem, iaculis interdum magna accumsan ac blandit."
msg1024="Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam placerat velit ac ex porta, id ultrices dui congue. Duis laoreet mi imperdiet neque ultricies, nec varius elit sagittis. Cras sapien orci, efficitur consectetur ligula ac, sollicitudin rhoncus augue. Donec auctor leo sed erat bibendum vehicula. Aenean in tellus pretium, viverra dolor a, elementum metus. Aliquam tortor neque, lobortis ut suscipit a, pretium at est. Cras lacinia ante sit amet elit eleifend rutrum. Etiam a leo nulla. Duis imperdiet metus at libero feugiat, at pulvinar massa aliquam.Etiam et tempor velit. Curabitur mi tortor, placerat non est in, fringilla scelerisque orci. In vel nunc bibendum, maximus magna a, eleifend dui. Duis augue purus, lobortis ac dui at, porta rhoncus urna. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Mauris augue leo, bibendum efficitur pellentesque eget, efficitur ut elit. Curabitur ornare lacinia sapien nec consectetur. Ut consequat mattis nisl. Curabitur dolor."
msg2048="Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed quis metus euismod, iaculis purus vel, viverra nulla. Suspendisse posuere mattis purus, ut suscipit risus blandit sed. Maecenas porttitor, diam sit amet lobortis congue, felis nisi molestie enim, vel pretium quam neque eget urna. Nulla facilisi. Nullam sed lacus eget quam pulvinar eleifend eleifend vitae nulla. Mauris accumsan accumsan mi, nec sagittis massa dignissim eget. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae;Etiam pellentesque volutpat diam eu eleifend. Aliquam egestas odio ex, accumsan pulvinar orci commodo at. Nam sed efficitur sapien. Morbi in tincidunt eros. Donec quis imperdiet quam. Donec eget lacus luctus, dapibus tortor id, aliquet odio. Phasellus et sem lacus. Integer vitae justo vitae sapien suscipit tristique. Donec suscipit mattis euismod. Aliquam quis mollis ligula.Curabitur vehicula dui vitae sem sagittis, id interdum tortor elementum. Maecenas pretium enim et ex ullamcorper vulputate. Cras pretium suscipit massa. Pellentesque a sodales tortor. Nullam imperdiet venenatis erat nec tempus. Integer leo turpis, rutrum a scelerisque ac, mollis ultrices magna. Pellentesque vel velit venenatis, tempor magna quis, porta ipsum. Nunc rutrum, libero ac convallis laoreet, magna nisl blandit felis, in eleifend quam arcu ac purus. Nunc tincidunt congue nisi, at posuere odio ornare in. Curabitur sed vulputate libero. Phasellus finibus lorem vel arcu interdum, sed ultrices odio laoreet. Curabitur et ultricies nisi. Fusce nec diam convallis ex sollicitudin mattis. Phasellus vitae lorem et odio rhoncus tempus id malesuada nisl. Mauris volutpat at est bibendum tincidunt.Quisque lacus velit, egestas non purus vitae, lobortis viverra felis. Nullam faucibus vel magna sit amet suscipit. Nulla ac tempor urna. Fusce dapibus, urna eu gravida semper, diam tellus gravida arcu, non interdum nunc lectus sit amet nisi. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut fermentum, neque vitae pretium cras amet."
msgNULL=""
function prueba1
{
	in_files="_getline.c test/test_getline.c"
	echo "${in_files}"
	make build run=norun in_files="${in_files}"
	echo "message" | ./hsh
}
function prueba2
{
	msg="${msg2048}"
	in_files="_getline.c test/test_getline.c"
	echo "${in_files}"
	make build run=norun in_files="${in_files}" args="${msg}"
	echo "${msg}" | ./hsh
}
prueba2
prueba1