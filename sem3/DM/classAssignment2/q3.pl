% Type definition for binary trees
% A binary tree is either empty or a tree with an element and two subtrees
binary_tree(empty).
binary_tree(tree(Element, Left, Right)) :-
    binary_tree(Left),
    binary_tree(Right).

% Preorder traversal: Node, Left, Right
preorder(empty, []).
preorder(tree(Element, Left, Right), [Element|Rest]) :-
    preorder(Left, LeftRest),
    preorder(Right, RightRest),
    append(LeftRest, RightRest, Rest).

% In-order traversal: Left, Node, Right
inorder(empty, []).
inorder(tree(Element, Left, Right), Result) :-
    inorder(Left, LeftRest),
    inorder(Right, RightRest),
    append(LeftRest, [Element|RightRest], Result).

% Post-order traversal: Left, Right, Node
postorder(empty, []).
postorder(tree(Element, Left, Right), Result) :-
    postorder(Left, LeftRest),
    postorder(Right, RightRest),
    append(LeftRest, RightRest, Temp),
    append(Temp, [Element], Result).