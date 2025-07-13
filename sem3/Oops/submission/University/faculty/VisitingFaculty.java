package faculty;

public class VisitingFaculty extends FacultyDatabase {
    public VisitingFaculty(int ID, String Name, String Phone) {
        super(ID, Name, Phone);
    }

    public String getRole() {
        return "Visiting Faculty";
    }
}