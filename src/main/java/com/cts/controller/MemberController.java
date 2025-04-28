package com.cts.controller;



import com.cts.dto.MemberRequest;
import com.cts.model.Member;
import com.cts.service.MemberService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/api/members")
public class MemberController {

    @Autowired
    private MemberService memberService;

    // Member Registration
    @PostMapping("/register")
    public Member registerMember(@RequestBody MemberRequest memberDTO) {
        return memberService.registerMember(memberDTO);
    }

    // Admin - View All Members
    @GetMapping
    public List<Member> getAllMembers() {
        return memberService.getAllMembers();
    }

    // Admin - Update Member Details
    @PutMapping("/{memberId}")
    public Member updateMember(@PathVariable Long memberId, @RequestBody MemberRequest memberDTO) {
        return memberService.updateMember(memberId, memberDTO);
    }

    // Admin - Update Only Membership Status
    @PatchMapping("/{memberId}/status")
    public Member updateMembershipStatus(@PathVariable Long memberId, @RequestParam String membershipStatus) {
        return memberService.updateMembershipStatus(memberId, membershipStatus);
    }

    // Admin - Delete Member
    @DeleteMapping("/{memberId}")
    public String deleteMember(@PathVariable Long memberId) {
        memberService.deleteMember(memberId);
        return "Member deleted successfully!";
    }
}


