package University;
import java.util.ArrayList;
import java.util.List;

import faculty.FacultyDatabase;
import faculty.RegularFaculty;
import faculty.VisitingFaculty;
import students.StudentDatabase;
import students.ActiveStudents;
import students.Alumni;

public class main {
    public static void main(String[] args) {
        UniversityMemberDatabase A = new ActiveStudents(1, "A", "123");
        UniversityMemberDatabase B = new RegularFaculty(2, "B", "456");
        UniversityMemberDatabase C = new Alumni(3, "C", "789");
        UniversityMemberDatabase D = new VisitingFaculty(4, "D", "012");

        System.out.println(A.getFullDetails());
        System.out.println(B.getFullDetails());
        System.out.println(C.getFullDetails());
        System.out.println(D.getFullDetails());
    }
}

interface UniversityMember {
    String getName();
    String getRole();
    int getId();
    String getPhoneNumber();
    String getFullDetails();
}

abstract class UniversityMemberDatabase{
    public static int numberOfMembers = 0;
    private int ID;
    private String Name;
    private String Phone;
    private int memberNumber;
    private static List<String> Members = new ArrayList<>();

    public UniversityMemberDatabase(int ID, String Name, String Phone) {
        this.ID = ID;
        this.Name = Name;
        this.Phone = Phone;
        this.memberNumber = numberOfMembers;
        numberOfMembers++;
        addMember();
    }

    // Abstract method declarations without bodies
    abstract void addMember();

    abstract String getMembers();

    public int getId() {
        return ID;
    }

    public String getName() {
        return Name;
    }

    public String getPhoneNumber() {
        return Phone;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public void setName(String Name) {
        this.Name = Name;
    }

    public void setPhone(String Phone) {
        this.Phone = Phone;
    }

    public abstract String getRole();

    public String getFullDetails() {
        return "ID of member: " + ID + ", Name of member: " + Name + ", Phone number: " + Phone + ", Role of member: " + getRole();
    }

    protected void addToMembersList(String name) {
        Members.add(name);
    }

    protected String getAllMembers() {
        return String.join(", ", Members);
    }
}
