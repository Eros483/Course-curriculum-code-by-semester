package faculty;

public class RegularFaculty extends FacultyDatabase {
    public RegularFaculty(int ID, String Name, String Phone) {
        super(ID, Name, Phone);
    }

    public String getRole() {
        return "Regular Faculty";
    }
}

