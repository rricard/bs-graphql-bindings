type location = Js.t {. line : int, column : int};

type source = Js.t {. body : string, name : string, locationOffset : location};

type astNode;
